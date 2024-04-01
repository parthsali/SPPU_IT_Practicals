const express = require('express');
const app = express();
const cors = require('cors');



const UserRoutes = require('./routes/UserRoutes');

app.use(express.json());
app.use(cors());
app.use('/api/auth', UserRoutes);

app.listen(8000, () => {
    console.log("Server is running on port 8000");
}
);
