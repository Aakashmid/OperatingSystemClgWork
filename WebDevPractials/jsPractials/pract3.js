function validateForm() {
    // Clear previous errors
    document.getElementById("nameError").innerText = "";
    document.getElementById("emailError").innerText = "";
    document.getElementById("ageError").innerText = "";
    document.getElementById("genderError").innerText = "";
    document.getElementById("termsError").innerText = "";
    document.getElementById("successMessage").innerText = "";

    // Get form values
    const name = document.getElementById("name").value.trim();
    const email = document.getElementById("email").value.trim();
    const age = document.getElementById("age").value.trim();
    const gender = document.getElementById("gender").value;
    const terms = document.getElementById("terms").checked;

    let isValid = true;

    // Validate name (only letters)
    if (!/^[a-zA-Z\s]+$/.test(name)) {
        document.getElementById("nameError").innerText = "Name must contain only letters.";
        isValid = false;
    }

    // Validate email (HTML5 type=email does basic check)
    if (email === "") {
        document.getElementById("emailError").innerText = "Email is required.";
        isValid = false;
    }

    // Validate age (non-empty and positive)
    if (age === "" || parseInt(age) <= 0) {
        document.getElementById("ageError").innerText = "Enter a valid age.";
        isValid = false;
    }

    // Validate gender selection
    if (gender === "") {
        document.getElementById("genderError").innerText = "Please select your gender.";
        isValid = false;
    }

    // Validate terms checkbox
    if (!terms) {
        document.getElementById("termsError").innerText = "You must agree to the terms.";
        isValid = false;
    }

    // If all validations pass
    if (isValid) {
        document.getElementById("successMessage").innerText = "Form submitted successfully!";
    }

    return false; // Prevent actual form submission for demo
}