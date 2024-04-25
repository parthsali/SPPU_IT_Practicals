## Assignment-03-B : Node.js Server Creation and MongoDB Integration

#### This document provides an overview of Node.js server creation and details about [Node.js](https://nodejs.org/en) and [MongoDB](https://www.mongodb.com/).

### Node.js Server Creation

#### Node.js allows you to execute JavaScript code outside of a web browser, enabling server-side development for building web applications and APIs. Here's a basic workflow for creating a Node.js server:

- **1. Project Setup:** Create a directory for your project and initialize a `package.json` file using `npm init -y` or `yarn init -y`.

- **2. Main Server File:** Create a JavaScript file (e.g., `server.js`) to house your server logic. You'll likely use the `http` or `https` modules to create an HTTP server.

- **3. Dependencies:** If required, install additional modules using `npm install <module_name>` or `yarn add <module_name>`. Common server-side modules include:

  - `express`: Web framework for building robust APIs and web applications (https://expressjs.com/)
  - `body-parser`: Parse incoming request bodies containing JSON or form data (http://expressjs.com/en/resources/middleware/body-parser.html)
  - `cors`: Enables Cross-Origin Resource Sharing (CORS) for secure cross-origin requests (https://expressjs.com/en/resources/middleware/cors.html)

- **4. Server Logic:** Write server code that defines endpoints for handling requests, interacts with databases (potentially MongoDB), and returns responses.

- **5. Running the Server:** Execute the server file using `node server.js` (or `nodemon server.js` for hot reloading) in your terminal.

### Node.js and MongoDB

**Node.js:** Provides a JavaScript runtime environment for server-side development.

**MongoDB:** A NoSQL document-oriented database for flexible data storage.

### Integration:

#### Node.js and MongoDB can be combined to build powerful web applications. Here's how they work together:

- **Node.js Drivers:** Libraries like the official MongoDB Node.js Driver facilitate communication between your Node.js application and MongoDB. (https://www.mongodb.com/docs/drivers/node/current/)

- **Object Data Modeling (ODM):** Libraries like Mongoose offer a high-level interface for interacting with MongoDB using familiar object-oriented concepts. Mongoose allows you to define data models (schemas) that map to MongoDB collections and provides methods for CRUD operations (Create, Read, Update, Delete) on documents. (https://www.mongodb.com/developer/languages/javascript/getting-started-with-mongodb-and-mongoose/)
