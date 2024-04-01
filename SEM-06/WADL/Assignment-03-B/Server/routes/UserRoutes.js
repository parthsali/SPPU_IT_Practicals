const router = require('express').Router();

const { Login, Register, getAllUsers, updateUser, deleteUser } = require('../controllers/UserController');


router.post('/login', Login);
router.post('/register', Register);

router.get('/all', getAllUsers);


router.put('/update', updateUser);

router.delete('/delete', deleteUser);



module.exports = router;

