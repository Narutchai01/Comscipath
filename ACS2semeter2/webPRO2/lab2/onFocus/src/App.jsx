import { useState } from "react";

function App() {
  const [User, setUser] = useState(false);
  const [Required, setRequired] = useState(false);

  return (
    <>
      <form style={{width : "500px", height : "500px"}}>
        <h1>Contact</h1>
        <fieldset
          style={
            User ? { backgroundColor: "red" } : { backgroundColor: "white" }
          }
        >
          <legend>User</legend>
          <label htmlFor="">
            Name:
            <input
              type="text"
              name="name"
              onFocus={(e) => {
                e.stopPropagation();
                setUser(true);
              }}
              onBlur={() => setUser(false)}
            />
          </label>
          <label htmlFor="">
            Email:
            <input
              type="text"
              name="name"
              onFocus={(e) => {
                e.stopPropagation();
                setUser(true);
              }}
              onBlur={() => setUser(false)}
            />
          </label>
        </fieldset>
        <fieldset
          style={
            Required ? { backgroundColor: "red" } : { backgroundColor: "white" }
          }
        >
          <legend>User</legend>
          <label htmlFor="">
            Subject:
            <input
              type="text"
              name="name"
              onFocus={(e) => {
                e.stopPropagation();
                setRequired(true);
              }}
              onBlur={() => setRequired(false)}
            />
          </label>
          <label htmlFor="">
            Body:
            <input
              type="text"
              name="name"
              onFocus={(e) => {
                e.stopPropagation();
                setRequired(true);
              }}
              onBlur={() => setRequired(false)}
            />
          </label>
        </fieldset>
      </form>
    </>
  );
}

export default App;
