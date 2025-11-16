// a. Print factors of a number
function printFactors() {
    const num = parseInt(document.getElementById("numFactors").value);
    const factors = [];
    for (let i = 1; i <= num; i++) {
        if (num % i === 0) factors.push(i);
    }
    document.getElementById("factorsResult").innerText = `Factors: ${factors.join(", ")}`;
}

// b. Find smallest of five numbers
function findSmallest() {
    const inputs = document.querySelectorAll(".numInput");
    const numbers = Array.from(inputs).map(input => parseFloat(input.value));
    const smallest = Math.min(...numbers);
    document.getElementById("smallestResult").innerText = `Smallest number: ${smallest}`;
}

// c. Find factorial of a number
function findFactorial() {
    let num = parseInt(document.getElementById("numFactorial").value);
    let result = 1;
    for (let i = 2; i <= num; i++) {
        result *= i;
    }
    document.getElementById("factorialResult").innerText = `Factorial: ${result}`;
}

// d. Display multiplication table
function showTable() {
    const num = parseInt(document.getElementById("numTable").value);
    const resultList = document.getElementById("tableResult");
    resultList.innerHTML = "";
    for (let i = 1; i <= 10; i++) {
        const li = document.createElement("li");
        li.textContent = `${num} × ${i} = ${num * i}`;
        resultList.appendChild(li);
    }
}