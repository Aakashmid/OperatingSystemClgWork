<!-- Write a PHP script to print the sum of even digits of a number -->
<?php
// Function to calculate sum of even digits
function sumEvenDigits($number) {
    $sum = 0;
    $digits = str_split($number); // Split number into individual digits

    foreach ($digits as $digit) {
        if (is_numeric($digit) && $digit % 2 == 0) {
            $sum += $digit;
        }
    }

    return $sum;
}

// Example usage
$inputNumber = 248913;
echo "Sum of even digits in $inputNumber is: " . sumEvenDigits($inputNumber);
?>