<!-- Design a Student Registration form, using appropriate input fields consisting of following

a. Roll Number
b. First Name
c. Last Name
d. Gender
e. Department
f. DOB

Submit, retrieve the form data using the S_POST variable and display it -->


<!DOCTYPE html>
<html>
<head>
    <title>Student Registration</title>
</head>
<body>

<h2>Student Registration Form</h2>


<form method="POST">
    Roll Number: <input type="text" name="roll" required><br><br>

    First Name: <input type="text" name="fname" required><br><br>

    Last Name: <input type="text" name="lname" required><br><br>

    Gender:
    <input type="radio" name="gender" value="Male" required> Male
    <input type="radio" name="gender" value="Female" required> Female
    <input type="radio" name="gender" value="Other" required> Other
    <br><br>

    Department:
    <select name="dept" required>
        <option value="Computer Science">Computer Science</option>
        <option value="Phycics">Phycics</option>
        <option value="Chemistry">Chemistry</option>
        <option value="Commerce">Commerce</option>
    </select>
    <br><br>

    DOB: <input type="date" name="dob" required><br><br>

    <input type="submit" value="Submit">
</form>

<?php
if ($_SERVER["REQUEST_METHOD"] === "POST") {
    $roll   = htmlspecialchars($_POST['roll']);
    $fname  = htmlspecialchars($_POST['fname']);
    $lname  = htmlspecialchars($_POST['lname']);
    $gender = htmlspecialchars($_POST['gender']);
    $dept   = htmlspecialchars($_POST['dept']);
    $dob    = htmlspecialchars($_POST['dob']);

    echo "<h3>Submitted Data</h3>";
    echo "Roll Number : $roll <br>";
    echo "First Name  : $fname <br>";
    echo "Last Name   : $lname <br>";
    echo "Gender      : $gender <br>";
    echo "Department  : $dept <br>";
    echo "DOB         : $dob <br>";

    echo "<br><a href='prob3.php'>Go Back</a>";
    exit;
}
?>
</body>
</html>
