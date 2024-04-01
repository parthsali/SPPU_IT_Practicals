import { useState } from "react";
import "./Dashboard.css";

let data = [
  {
    username: "Parth",
    email: "parth@gmail.com",
    rollNo: "123",
  },
  {
    username: "Raj",
    email: "raj@gmail.com",
    rollNo: "456",
  },
  {
    username: "Rahul",
    email: "rahul@gmail.com",
    rollNo: "789",
  },
];

const Dashboard = () => {
  const [users, setUsers] = useState(data);

  const handleDelete = (index) => {
    const updatedUsers = [...users];
    updatedUsers.splice(index, 1);
    setUsers(updatedUsers);
  };

  return (
    <div>
      <h1>Users Data</h1>
      <table>
        <thead>
          <tr>
            <th>Username</th>
            <th>Email</th>
            <th>Roll No</th>
            <th>Action</th>
          </tr>
        </thead>
        <tbody>
          {users.map((user, index) => (
            <tr key={index}>
              <td>{user.username}</td>
              <td>{user.email}</td>
              <td>{user.rollNo}</td>
              <td>
                <button onClick={() => handleDelete(index)}>Delete</button>
              </td>
            </tr>
          ))}
        </tbody>
      </table>
    </div>
  );
};

export default Dashboard;
