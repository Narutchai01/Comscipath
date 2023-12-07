const express = require('express');
const app = express();
const port = 4664;
const {PofileData} = require('./model/PofileData');
const {uuid} = require('uuidv4');
const {MongoClient} = require('mongodb');


const client = new MongoClient('mongodb+srv://123:123@cluster0.xy9xqw8.mongodb.net/');

const ConnectDB = async () => {
    try {
        await client.connect();
        console.log('Connected to DB');
    } catch (error) {
        console.log(error);
    }
}


app.use(express.json());



app.get('/', (req, res) => {
    console.log("Request is coming");
    res.send('This is lab test 2');
});


app.post('/adduser', async (req, res) => {
    try {
        await ConnectDB();
        const { username , name , img_url , post , follower , following } = req.body;
        const newPofile = {
            id: uuid(),
            username,
            name,
            img_url,
            post,
            follower,
            following
        };
        const result = client.db('labtest2').collection('profile').insertOne(newPofile);
        res.send({
            message: 'Profile created successfully',
            data: newPofile,
            result: result
        });
    } catch (error) {
        console.log(error);
    }
});


app.get('/getuser/:username', async (req, res) => {
    try {
        const {username} = req.params;
        await ConnectDB();
        const result = await client.db('labtest2').collection('profile').findOne({username: username});
        res.send({
            message: 'Profile found',
            data: result
        });
    } catch (error) {
        res.send({message:"“You are lost in the galaxy far far away"})
    }
});

app.listen(port, () => {
    console.log(`Server listening at http://localhost:${port}`);
});