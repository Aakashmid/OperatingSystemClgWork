#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

class MemoryManager {
    struct MemoryBlock {
        int size;
        int job_id;
        int job_size;
        bool occupied;
        
        MemoryBlock(int s) : size(s), job_id(-1), job_size(0), occupied(false) {}
    };

    vector<MemoryBlock> blocks;
    vector<int> processes;

private:
    void resetBlocks() {
        for(auto& block : blocks) {
            block.job_id = -1;
            block.job_size = 0;
            block.occupied = false;
        }
    }

public:
    void input() {
        int block_count, process_count;
        
        cout << "Enter number of memory blocks: ";
        cin >> block_count;
        blocks.clear();  // clear blocks if they have  elements
        
        cout << "Enter block sizes:\n";
        for(int i=0; i<block_count; i++) {
            int size;
            cin >> size;
	    MemoryBlock mb(size);
	    blocks.push_back(mb);
            //blocks.emplace_back(size);
        }

        cout << "Enter number of processes: ";
        cin >> process_count;
        processes.resize(process_count); // resizes processes array 
        
        cout << "Enter process sizes:\n";
        for(int i=0; i<process_count; i++) {
            cin >> processes[i];
        }
    }


    // first-fit implementation
    void firstFit() {
        resetBlocks();  // unoccupy each 
        for(int pid=0; pid<processes.size(); pid++) {
            for(auto& block : blocks) {
                if(!block.occupied && block.size >= processes[pid]) {
                    block.job_id = pid + 1;
                    block.job_size = processes[pid];
                    block.occupied = true;
                    break;
                }
            }
        }
    }


    void bestFit() {
        resetBlocks();
        for(int pid=0; pid<processes.size(); pid++) {
            int best_idx = -1;
            for(int j=0; j<blocks.size(); j++) {
                if(!blocks[j].occupied && blocks[j].size >= processes[pid]) {
                    if(best_idx == -1 || blocks[j].size < blocks[best_idx].size) {  // update best idx when find block of less size 
                        best_idx = j;
                    }
                }
            }
            if(best_idx != -1) {
                blocks[best_idx].job_id = pid + 1;
                blocks[best_idx].job_size = processes[pid];
                blocks[best_idx].occupied = true;
            }
        }
    }


    void worstFit() {
        resetBlocks();
        for(int pid=0; pid<processes.size(); pid++) {
            int worst_idx = -1;
            for(int j=0; j<blocks.size(); j++) {
                if(!blocks[j].occupied && blocks[j].size >= processes[pid]) {
                    if(worst_idx == -1 || blocks[j].size > blocks[worst_idx].size) {
                        worst_idx = j;
                    }
                }
            }
            if(worst_idx != -1) {
                blocks[worst_idx].job_id = pid + 1;
                blocks[worst_idx].job_size = processes[pid];
                blocks[worst_idx].occupied = true;
            }
        }
    }

    // display memory blocks  after allocation
    void display() {
	cout << "\nMemory Block Size\tJob Number\tJob Size\tStatus\t\tInternal Fragmentation\n";

    	int total_memory = 0, total_used = 0;

    	for (const auto& block : blocks) {
            cout << block.size << "\t\t\t";

            if (block.occupied) {
             	cout << block.job_id << "\t\t";
             	cout << block.job_size << "\t\t";
             	cout << "Busy\t\t";
            	cout << block.size - block.job_size;
            	total_used += block.job_size;
       	    }else {
            	cout << "-\t\t";
            	cout << "-\t\t";
           	cout << "Free\t\t";
            	cout << block.size;
             }

            cout << "\n";
            total_memory += block.size;
    	}

	cout<<"\nTotal Memory : "<<total_memory<<endl;
	cout<<"Total used memory : "<< total_used<<endl;
	cout<<"Tatal Internal fragementation :"<<total_memory-total_used<<endl;

    }

};

int main() {
    MemoryManager manager;
    int choice;
    
    do {
        cout << "\nMemory Allocation Strategies:\n"
             << "1. First Fit\n2. Best Fit\n3. Worst Fit\n4. Exit\n"
             << "Enter choice: ";
        cin >> choice;
        
        if(choice == 4) break;  // before taking input checking for valid choice
        
        manager.input(); // take inputs
        
        switch(choice) {
            case 1: manager.firstFit(); break;
            case 2: manager.bestFit(); break;
            case 3: manager.worstFit(); break;
            default: cout << "Invalid choice!\n";
        }
        
        manager.display();
        
    } while(true);

    return 0;
}

