const db = require("../db/db.json");
const fs = require("fs");


const Login = async (req, res) => {
    const { email, password } = req.body;
    try {
        console.log(req.body)
        let data = await fs.readFileSync("db/db.json", "utf-8");
        data = JSON.parse(data);

        const users = data.users;


        const user = users.find(user => user.email === email && user.password === password);

        if (!user) {
            return res.status(404).json({ message: "User not found" });
        }


        return res.status(200).json({ message: "User logged in", user: user },);


    }
    catch (error) {
        return res.status(500).json({ message: error });
    }
};

const Register = async (req, res) => {
    const { name, username, email, password } = req.body;
    console.log(req.body)
    try {
        let data = await fs.readFileSync("db/db.json", "utf-8");
        data = JSON.parse(data);

        const users = data.users;

        const user = users.find(user => user.email === email);

        if (user) {
            return res.status(400).json({ message: "User already exists" });
        }

        users.push({ name, username, email, password });

        data.users = users;

        await fs.writeFileSync("db/db.json", JSON.stringify(data));

        return res.status(200).json({ message: "User registered" });

    }
    catch (error) {
        return res.status(500).json({ message: "Internal server error" });
    }

}

const getAllUsers = async (req, res) => {
    try {
        let data = await fs.readFileSync("db/db.json", "utf-8");
        data = JSON.parse(data);

        const users = data.users;

        return res.status(200).json(users);
    }
    catch (error) {
        return res.status(500).json({ message: "Internal server error" });
    }
}

const getUserUsingMail = async (req, res) => {
    const { email } = req.body;
    try {
        const user = await User
            .findOne({ email })

        if (!user) {
            return res.status(404).json({ message: "User not found" });
        }

        return res.status(200).json(user);
    }
    catch (error) {
        return res.status(500).json({ message: "Internal server error" });
    }
}

const updateUser = async (req, res) => {
    const { email, username, password } = req.body;
    try {
        const user = await User
            .findOneAndUpdate
            (
                { email },
                { username, password },
                { new: true }
            );

        if (!user) {
            return res.status(404).json({ message: "User not found" });
        }

        return res.status(200).json(user);

    }
    catch (error) {
        return res.status(500).json({ message: "Internal server error" });
    }
}

const deleteUser = async (req, res) => {
    const { email } = req.body;

    try {
        console.log(req.body)
        let data = await fs.readFileSync("db/db.json", "utf-8");
        data = JSON.parse(data);

        let users = data.users;

        let user = users.find(user => user.email === email);

        if (!user) {
            return res.status(404).json({ message: "User not found" });
        }

        const newUsers = users.filter(user => user.email !== email);

        data.users = newUsers;

        await fs.writeFileSync("db/db.json", JSON.stringify(data));

        return res.status(200).json({ message: "User deleted" });
    }
    catch (error) {
        return res.status(500).json({ message: error.message });
    }
}

module.exports = { Login, Register, getAllUsers, updateUser, deleteUser };