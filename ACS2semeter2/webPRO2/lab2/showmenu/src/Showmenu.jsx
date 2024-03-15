import "./App.css";
import { useState } from "react";

const Menu = () => {
  return (
    <>
      <div>
        <h1>Menu</h1>
      </div>
    </>
  );
};

function App() {
  const [showMenu, setShowMenu] = useState(false);
  return (
    <>
      <div
        style={{ width: "100vw", height: "100vh"}}
        onPointerDown={() => setShowMenu(false)}
      >
        <button
          onClick={async (e) => {
            await e.stopPropagation();
            setShowMenu(!showMenu);
          }}
        >
          {!showMenu ? "Menu" : "Menu Close"}
        </button>
        {showMenu ? <Menu /> : null}
      </div>
    </>
  );
}

export default App;
