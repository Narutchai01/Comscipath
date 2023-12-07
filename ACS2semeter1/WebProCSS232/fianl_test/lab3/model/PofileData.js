const mongoose = require('mongoose');
const Schema = mongoose.Schema;

const ProfileSchema = new Schema({
    id:String,
    username: String,
    name: String,
    img_url: String,
    post:Number,
    follower:Number,
    following:Number,
});


const PofileData = mongoose.model('PofileData', ProfileSchema);

module.exports = PofileData;