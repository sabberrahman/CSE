![[Pasted image 20250308200526.png]]

![[Pasted image 20250308200607.png]]

![[Pasted image 20250308200859.png]]


![[Pasted image 20250308201056.png]]



![[Pasted image 20250308201132.png]]


![[Pasted image 20250308202453.png]]

![[Pasted image 20250308204837.png]]


![[Pasted image 20250308205022.png]]


```js
// Import necessary libraries
const express = require('express');
const app = express();
const port = 3000;

// Define the API endpoint
app.get('/api/dashboardData', async (req, res) => {
  try {
    // Retrieve query parameters
    const page = req.query.page; // Access the `page` query parameter
    const filterParams = req.query.filterParams; // Access the `filterParams` query parameter
    
    // Validate or process the parameters as needed
    if (!page || !filterParams) {
      return res.status(400).json({ error: 'Missing required parameters' });
    }

    // Fetch or generate the data you need (e.g., from a database)
    const dashboardData = await getDashboardData(page, filterParams);

    // Send the response as JSON
    res.json(dashboardData);

  } catch (error) {
    console.error('Error fetching dashboard data:', error);
    res.status(500).json({ error: 'Internal Server Error' });
  }
});

// Function to simulate data retrieval (replace with actual logic)
async function getDashboardData(page, filterParams) {
  // Simulate fetching data based on page and filter parameters
  return {
    page,
    filterParams,
    data: [/* Your simulated data here */],
  };
}

// Start the server
app.listen(port, () => {
  console.log(`Server running at http://localhost:${port}`);
});




-------------------cient req----------------

const page = 1; // Example page number
const filterParams = "filter=example"; // Example filter query

const response = await fetch(`/api/dashboardData?page=${page}&${filterParams}`);
const data = await response.json(); // Parse the JSON response

console.log(data); // Process the returned data

-----bbttere0---------
const express = require('express');
const app = express();
const dashboardRoutes = require('./routes/dashboardRoutes');

app.use('/api', dashboardRoutes);  // Use routes in a modular way

const port = 3000;
app.listen(port, () => {
  console.log(`Server running at http://localhost:${port}`);
});



```

![[Pasted image 20250308210858.png]]

```ts
const getDashboardData = async (req, res) => {
  try {
    const { page, filterParams } = req.query;

    if (!page || !filterParams) {
      return res.status(400).json({ error: 'Missing required parameters' });
    }

    const data = await fetchData(page, filterParams);  // Replace with real data fetching logic
    res.json(data);
  } catch (error) {
    console.error('Error:', error);
    res.status(500).json({ error: 'Internal Server Error' });
  }
};

const fetchData = async (page, filterParams) => {
  // Simulate data fetching
  return {
    page,
    filterParams,
    data: ["item1", "item2", "item3"], // Simulate data
  };
};

module.exports = { getDashboardData };

```

![[Pasted image 20250308211354.png]]












