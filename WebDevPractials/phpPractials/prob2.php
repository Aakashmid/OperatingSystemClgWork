<!-- Write a PHP script to print the sum of even digits of a number -->

<?php
echo "Enter a number: ";
$number = trim(fgets(STDIN));

for ($i = 1; $i <= 10; $i++) {
    echo $number . " x " . $i . " = " . ($number * $i) . PHP_EOL;
}
?>