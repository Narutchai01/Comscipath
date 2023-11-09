const express = require('express');
const app = express();

app.use(express.json())

const PORT = 3000;

// mock data
const characters = [
    {
        id: '001',
        name: 'Iron man',
        category: 'Hero',
        Level: 99
    },
    {
        id: '002',
        name: 'Batman',
        category: 'Hero',
        Level: 38
    },
    {
        id: '003',
        name: 'Joker',
        category: 'Villian',
        Level: 70
    }
];

// app.get('/characters', (req, res) => {
//   res.json(characters);
// });

// app.get('/characters/:id', (req, res) => {
//   const { id } = req.params;
//   const result = characters.find((character) => characters.id === id);
//   res.json(result);
// });

// app.post('/characters', (req, res) => {
//   const payload = req.body;
//   res.json(payload);
// });

// app.put('/characters/:id', (req, res) => {
//   const { id } = req.params;
//   res.json({ id });
// });

// app.delete('/characters/:id', (req, res) => {
//   const { id } = req.params;
//   res.json({ id });
// });

app.get('/', (req, res) => {
    res.json({ message: 'Test without db' });
});

app.listen(PORT, () => {
    console.log('Server is running');
});
