const express = require('express');
const app = express();
const mongoose = require('mongoose');
const Character = require('./model/character');

app.use(express.json())

const PORT = 3000;

mongoose.connect('mongodb+srv://css:css@cluster0.q2nwv4h.mongodb.net/', {
    useNewUrlParser: true
});

const connection = mongoose.connection;
connection.once("open", () => {
    console.log("MongoDB database connected.");
});

app.get('/characters', async (req, res) => {
    const result = await Character.find({});
    res.send(result);
});

app.post('/characters', async (req, res) => {
    try {
        console.log('req.body: ', req.body);

        const newCharacter = new Character({
            id: req.body.id,
            name: req.body.name,
            category: req.body.category,
            level: req.body.level,
        });

        await Character.create(newCharacter);
        res.send("Character added");
    } catch (err) {
        console.log("error: ", err);
    }
});

app.get('/characters/ironman', async (req, res) => {
    const result = await Character.find({ name: 'Iron man' }).exec();
    console.log(result);
    res.json(result);
});

app.get('/characters/:name', async (req, res) => {
    const { name } = req.params;
    const result = await Character.find({ name }).exec();
    console.log(result);
    res.json(result);
});

app.put('/characters/:id', async (req, res) => {
    const { id } = req.params;
    const { name, category, level } = req.body;
    const result = await Character.updateOne({ id }, { name, category, level });
    res.json(result);
});

app.delete('/characters/:id', async (req, res) => {
    const { id } = req.params;
    const result = await Character.deleteOne({ id });
    res.json(result);
});

app.listen(PORT, () => {
    console.log('Server is running');
});