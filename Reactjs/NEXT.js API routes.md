API Routes in Next.js provide a straightforward method to create API endpoints within a Next.js application. They allow developers to build serverless functions that can handle HTTP requests without setting up a separate backend server.

### Key Characteristics

1. Located in the `pages/api` directory
2. Create serverless functions that run on the server
3. Support various HTTP methods (GET, POST, PUT, DELETE, etc.)
4. Can interact with databases, external APIs, and perform server-side logic

```js
// pages/api/users/index.js
import { connectToDatabase } from '../../../lib/database';

export default async function handler(req, res) {
  const { method } = req;

  // Connect to database
  const db = await connectToDatabase();

  switch (method) {
    case 'GET':
      try {
        // Retrieve all users
        const users = await db.collection('users').find({}).toArray();
        res.status(200).json({ success: true, data: users });
      } catch (error) {
        res.status(400).json({ success: false, message: error.message });
      }
      break;

    case 'POST':
      try {
        // Create a new user
        const { name, email } = req.body;
        
        // Validate input
        if (!name || !email) {
          return res.status(400).json({ 
            success: false, 
            message: 'Name and email are required' 
          });
        }

        const newUser = await db.collection('users').insertOne({ name, email });
        
        res.status(201).json({ 
          success: true, 
          data: { 
            id: newUser.insertedId, 
            name, 
            email 
          } 
        });
      } catch (error) {
        res.status(400).json({ success: false, message: error.message });
      }
      break;

    default:
      res.setHeader('Allow', ['GET', 'POST']);
      res.status(405).end(`Method ${method} Not Allowed`);
  }
}
```

###### auth
```ts
// pages/api/auth/login.js
import jwt from 'jsonwebtoken';
import { comparePasswords } from '../../../lib/auth';

export default async function handler(req, res) {
  if (req.method !== 'POST') {
    return res.status(405).json({ message: 'Method not allowed' });
  }

  const { email, password } = req.body;

  try {
    // Simulate user lookup (replace with actual database query)
    const user = await findUserByEmail(email);

    if (!user) {
      return res.status(401).json({ message: 'Invalid credentials' });
    }

    // Verify password
    const isValidPassword = await comparePasswords(password, user.passwordHash);

    if (!isValidPassword) {
      return res.status(401).json({ message: 'Invalid credentials' });
    }

    // Generate JWT token
    const token = jwt.sign(
      { 
        userId: user.id, 
        email: user.email 
      }, 
      process.env.JWT_SECRET, 
      { expiresIn: '1h' }
    );

    res.status(200).json({ 
      token, 
      user: { 
        id: user.id, 
        email: user.email 
      } 
    });
  } catch (error) {
    res.status(500).json({ message: 'Authentication failed', error: error.message });
  }
}
```

#### The `handler` function in API routes is a powerful method that manages:

- HTTP Method Routing (GET, POST, PUT, DELETE)
- Request Body Parsing
- Query Parameter Handling
- Error Management
- Response Formatting

```ts
export default async function handler(req, res) {
  // Destructure method and body
  const { method, body, query } = req;

  // Method-based routing
  switch (method) {
    case 'GET':
      // Handle GET requests
      // Access query parameters
      const { id } = query;
      break;

    case 'POST':
      // Handle POST requests
      // Access request body
      const { name, email } = body;
      break;

    case 'PUT':
      // Update operations
      break;

    case 'DELETE':
      // Delete operations
      break;

    default:
      // Handle unsupported methods
      res.setHeader('Allow', ['GET', 'POST', 'PUT', 'DELETE']);
      res.status(405).end(`Method ${method} Not Allowed`);
  }
}
```

```js
// pages/api/users.js
export function getUserHandler(req, res) {
  // GET logic
  res.status(200).json({ method: 'GET' });
}

export function createUserHandler(req, res) {
  // POST logic
  res.status(201).json({ method: 'POST' });
}

export function updateUserHandler(req, res) {
  // PUT logic
  res.status(200).json({ method: 'PUT' });
}

export default function handler(req, res) {
  const { method } = req;

  switch (method) {
    case 'GET':
      return getUserHandler(req, res);
    case 'POST':
      return createUserHandler(req, res);
    case 'PUT':
      return updateUserHandler(req, res);
    default:
      res.setHeader('Allow', ['GET', 'POST', 'PUT']);
      res.status(405).end(`Method ${method} Not Allowed`);
  }
}
```
**API Routes**

- Backend logic
- Database interactions
- Authentication
- External API communication