document.getElementById('contactForm').addEventListener('submit', function (e) {
    e.preventDefault(); // Prevent form from refreshing the page

    const name = document.getElementById('name').value.trim();
    const email = document.getElementById('email').value.trim();

    if (name === "" || email === "") {
        alert("Please fill in all fields.");
        return;
    }

    // Display success message
    const responseDiv = document.getElementById('response');
    responseDiv.classList.remove('d-none');
    responseDiv.textContent = `Thank you, ${name}! We'll contact you at ${email}.`;

    // Clear form fields
    document.getElementById('contactForm').reset();
});
