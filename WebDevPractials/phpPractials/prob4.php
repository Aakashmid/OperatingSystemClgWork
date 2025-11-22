<!-- Write PHP Code to create a database, connect to it, create tables, insert and access their contents -->

<?php
// Connect to SQLite (creates file if not exists)
$conn = new PDO("sqlite:college.db");

// Create table
$conn->exec("CREATE TABLE IF NOT EXISTS Students (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    firstname TEXT,
    lastname TEXT,
    email TEXT
)");

// Insert data
$conn->exec("
            INSERT INTO Students (firstname, lastname, email)
             VALUES 
             ('badal', 'kumar', 'pr_xyz@example.com'),
             ('suraj', 'kumar', 'sr_yx@example.com') ,
             ('sam', 'willson', 'sam@example.com')

             ");

// Retrieve data from table 
$result = $conn->query("SELECT * FROM Students");
foreach ($result as $row) {
    echo "  " . $row['id'] . " | " . $row['firstname'] . " " . $row['lastname'] . " | " . $row['email'] . " \n";
}
