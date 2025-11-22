   <!-- Write a PHP code to insert , delete , and retrieve data from the database . Create proper forms for performing the above operations. Display the messages such as “The record is added in the database!” when data is inserted into the database, “ A record is deleted from the database” when data is deleted from the database. Use appropriate  button names such as Add Data, Delete Data , and Display . -->

   <!DOCTYPE html>
   <html>

   <head>
       <title>PHP Database Operations</title>
       <link rel="stylesheet" href="prob5.css">
   </head>

   <body>
       <h2>Student Database Operations</h2>

       <!-- Insert Form -->
       <form method="post">
           <h3>Add Student</h3>
           First Name: <input type="text" name="firstname" required>
           Last Name: <input type="text" name="lastname" required>
           Email: <input type="email" name="email" required>
           <button type="submit" name="add">Add Data</button>
       </form>

       <!-- Delete Form -->
       <form method="post">
           <h3>Delete Student</h3>
           Student ID: <input type="number" name="id" required>
           <button type="submit" name="delete">Delete Data</button>
       </form>

       <!-- Display Form -->
       <form method="post">
           <button type="submit" name="display">Display</button>
       </form>

       <?php
        // Connect to SQLite
        $conn = new PDO("sqlite:college.db");

        // Create table if not exists
        $conn->exec("CREATE TABLE IF NOT EXISTS Students (
        id INTEGER PRIMARY KEY AUTOINCREMENT,
        firstname TEXT,
        lastname TEXT,
        email TEXT
    )");

        // Insert operation
        if (isset($_POST['add'])) {
            $fname = $_POST['firstname'];
            $lname = $_POST['lastname'];
            $email = $_POST['email'];

            $stmt = $conn->prepare("INSERT INTO Students (firstname, lastname, email) VALUES (?, ?, ?)");
            $stmt->execute([$fname, $lname, $email]);

            echo "<p style='color:green;'>The record is added in the database!</p>";
        }

        // Delete operation
        if (isset($_POST['delete'])) {
            $id = $_POST['id'];

            $stmt = $conn->prepare("DELETE FROM Students WHERE id = ?");
            $stmt->execute([$id]);

            echo "<p style='color:red;'>A record is deleted from the database!</p>";
        }

        // Display operation
        if (isset($_POST['display'])) {
            $result = $conn->query("SELECT * FROM Students");

            echo "<h3>Student Records</h3>";
            echo "<table>";
            echo "<tr><th>ID</th><th>First Name</th><th>Last Name</th><th>Email</th></tr>";

            foreach ($result as $row) {
                echo "<tr>";
                echo "<td>" . $row['id'] . "</td>";
                echo "<td>" . $row['firstname'] . "</td>";
                echo "<td>" . $row['lastname'] . "</td>";
                echo "<td>" . $row['email'] . "</td>";
                echo "</tr>";
            }

            echo "</table>";
        }
        ?>
   </body>

   </html>