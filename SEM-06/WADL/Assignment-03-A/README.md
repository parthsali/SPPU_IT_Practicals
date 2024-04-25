## Assignment-03-A : Node.js Static Website Server

This project demonstrates a Node.js server that serves a static website from the `public` directory. Users can access the website content (e.g., HTML, CSS, JavaScript) through a web browser.

**Code Breakdown:**

**index.js:**

The `index.js` file implements the core server logic:

- **Imports:**

  - `http`: Provides the HTTP server functionality.
  - `fs`: Used for file system operations (reading files).
  - `path`: Assists with file path manipulation.

- **Server Creation:**

  - `http.createServer((req, res) => { ... })`: Creates an HTTP server instance that handles incoming requests (`req`) and sends responses (`res`).

- **Request Handling:**

  - `let filePath = ...`: Constructs the path to the requested resource based on the URL.
  - `let extname = ...`: Extracts the file extension from the path.
  - `let contentType = ...`: Sets the appropriate content type header for the response based on the extension.
  - `fs.readFile(filePath, (err, content) => { ... })`:
    - Reads the requested file content using the specified path.
    - Handles errors:
      - `ENOENT`: If the file is not found (404 Not Found), serves a custom `404.html` page.
      - Other errors: Returns a generic 500 Internal Server Error.
    - On success:
      - Sets the response status code (200 OK) and content type header.
      - Sends the file content as the response body.

- **Server Startup:**
  - `const PORT = process.env.PORT || 5000;`: Defines the port on which the server will listen.
  - `server.listen(PORT, () => console.log(...));`: Starts the server on the specified port and logs a message upon successful startup.

**Directory Structure:**

```
server/
├── index.js  # Node.js server code
└── public/
    |___ assests/
    |___ index.html
    |___ style.css
```

**Running the Application:**

1. Save the code as `index.js` in the `Assignment-03-A` directory.
2. Make sure your static website files are present in the `public` directory.
3. Open a terminal in the `Assignment-03-A` directory and run: `node index.js`
4. Access your website in a web browser by visiting `http://localhost:<PORT>`, where `<PORT>` is the port specified in the code (default: 5000).

**Additional Notes:**

- This is a basic example. You can enhance it to support features like routing, serving dynamic content, and handling more complex file types.
- Consider security best practices for serving static content in a production environment.
