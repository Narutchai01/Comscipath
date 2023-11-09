const mongoose = require('mongoose');
const Schema = mongoose.Schema;

const characterSchema = new Schema({
    id: String,
    name: String,
    category: String,
    level: Number,
});

const CharacterModel = mongoose.model('Character', characterSchema);

module.exports = CharacterModel;