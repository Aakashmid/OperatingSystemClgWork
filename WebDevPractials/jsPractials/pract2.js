 function validateForm() {
      // Clear previous errors
      document.getElementById("idError").innerText = "";
      document.getElementById("nameError").innerText = "";
      document.getElementById("ageError").innerText = "";
      document.getElementById("successMessage").innerText = "";

      const id = document.getElementById("studentId").value.trim();
      const name = document.getElementById("studentName").value.trim();
      const age = document.getElementById("studentAge").value.trim();

      let isValid = true;

      // a. Validate Student ID (10-digit alphanumeric)
      const idPattern = /^[a-zA-Z0-9]{10}$/;
      if (!idPattern.test(id)) {
        document.getElementById("idError").innerText = "Student ID must be 10 alphanumeric characters.";
        isValid = false;
      }

      // b. Validate Name (alphabetical only)
      const namePattern = /^[a-zA-Z\s]+$/;
      if (!namePattern.test(name)) {
        document.getElementById("nameError").innerText = "Name must contain only letters.";
        isValid = false;
      }

      // c. Validate Age (non-empty)
      if (age === "") {
        document.getElementById("ageError").innerText = "Age is required.";
        isValid = false;
      }

      if (isValid) {
        document.getElementById("successMessage").innerText = "Registration successful!";
      }

      return false; // Prevent actual form submission for demo
    }