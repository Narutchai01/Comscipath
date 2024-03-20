import { useState } from "react";
function App() {
  const [qurity, setQurity] = useState(0);
  const [arr, setArr] = useState([]);

  const handdleChange = (e) => {
    setQurity(e.target.value);
  };

  const randomNumber = (min, max) => {
    return Math.floor(Math.random() * (max - min + 1)) + min;
  };

  const handlesubmit = (e) => {
    e.preventDefault();
    const numbARR = [];
    for (let i = 0; i < qurity; i++) {
      numbARR.push(randomNumber(1, 6));
    }
    setArr(numbARR);
  };

  return (
    <>
      <form onSubmit={handlesubmit}>
        <label>
          Input here
          <input type="number" onChange={handdleChange} />
        </label>
        <button>Random</button>
      </form>

      {arr.map((item, index) => (
        <p key={index}>{item}</p>
      ))}
      <h1>Sum : {arr.reduce((acc,cur)=>acc+cur,0)}</h1>
    </>
  );
}

export default App;
