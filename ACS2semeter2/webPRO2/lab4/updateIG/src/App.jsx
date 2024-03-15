import { useState } from "react";
import "./App.css";

function App() {
  const [dataUser, setDataUser] = useState({
    Name: "N.billion",
    Username: "Narutchai",
    Bio: "I'm a Developer",
    Gender: "Male",
    image: null,
  });
  const [file, setFile] = useState(null);
  const [editData, setEditData] = useState({
    Name: "",
    Username: "",
    Bio: "",
    Gender: "",
  });

  const handleChange = (e) => {
    setEditData({ ...editData, [e.target.name]: e.target.value });
  };
  const handleFile = (e) => {
    setFile(e.target.files[0]);
  };

  const handleSubmit = (e) => {
    e.preventDefault();
    setDataUser({
      Name: editData.Name || dataUser.Name,
      Username: editData.Username || dataUser.Username,
      Bio: editData.Bio || dataUser.Bio,
      Gender: editData.Gender || dataUser.Gender,
      image: file || dataUser.image,
    });
  };

  return (
    <>
      <div>
        <h1>Name: {dataUser.Name}</h1>
        <h1>Username : {dataUser.Username}</h1>
        <h1>Bio : {dataUser.Bio}</h1>
        <h1>Gender : {dataUser.Gender}</h1>
        <h1>Image : {dataUser.image ? dataUser.image.name : "not have"}</h1>
      </div>
      <fieldset>
      update profile
        <form onSubmit={handleSubmit}>
          <label>
            <h1>Update Profile</h1>
            <input type="file" onChange={handleFile} />
          </label>
          <label>
            Name
            <input type="text" name="Name" onChange={handleChange} />
          </label>
          <label>
            Username
            <input type="text" name="Username" onChange={handleChange} />
          </label>
          <label>
            Bio
            <textarea
              name="Bio"
              cols="30"
              rows="10"
              onChange={handleChange}
            ></textarea>
          </label>
          <div>
            <h1>Gender</h1>
            <label>
              Female
              <input
                type="radio"
                name="Gender"
                value="Female"
                onChange={handleChange}
              />
            </label>
            <label>
              Male
              <input
                type="radio"
                name="Gender"
                value="Male"
                onChange={handleChange}
              />
            </label>
          </div>
          <button>Update</button>
        </form>
      </fieldset>
    </>
  );
}

export default App;
