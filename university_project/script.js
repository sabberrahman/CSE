const username = "sabberrahman";
const url = `https://api.github.com/users/${username}/repos`;

fetch(url)
  .then(response => response.json())
  .then(data => {
    const repositoriesList = document.getElementById("repositories");

    data.forEach(repo => {
      const repositoryItem = document.createElement("li"); // Create a list item (li)
      repositoryItem.classList.add("repo-card"); // Add class for styling

      // Create HTML elements within the list item
      const nameElement = document.createElement("h3");
      nameElement.textContent = repo.name;

      const descriptionElement = document.createElement("p");
      descriptionElement.textContent = repo.description || "No description provided";

      const urlElement = document.createElement("a");
      urlElement.href = repo.html_url;
      urlElement.target = "_blank";
      urlElement.textContent = "View on GitHub";

      // Append elements to the list item
      repositoryItem.appendChild(nameElement);
      repositoryItem.appendChild(descriptionElement);
      repositoryItem.appendChild(urlElement);

      // Add the list item (containing the card content) to the existing list
      repositoriesList.appendChild(repositoryItem);
    });
  })
  .catch(error => {
    console.error(error); // Handle any errors
  });
