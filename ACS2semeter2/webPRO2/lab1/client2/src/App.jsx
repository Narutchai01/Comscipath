/* eslint-disable react/prop-types */
import { useState, useEffect } from "react";

const Box = ({ number }) => {
  return (
    <>
      <div style={{ display: "flex", gap: "20px" }}>
        {number.map((item, index) => {
          return <h1 key={index}>{item}</h1>;
        })}
      </div>
    </>
  );
};

function App() {
  const [counterRoll, setCouterRoll] = useState(0);
  const [arrnumber, setArrnumber] = useState([0, 0, 0]);
  const randomNumber = (min, max) => {
    return Math.floor(Math.random() * (max - min + 1) + min);
  };

  useEffect(() => {
    const updateArr = arrnumber.map(() => randomNumber(0, 5));
    setArrnumber(updateArr);
  }, [counterRoll]);
  return (
    <>
      <h1>Roll : {counterRoll}</h1>
      <button onClick={()=>setCouterRoll(counterRoll+1)}>Roll</button>
      <Box number={arrnumber} />
    </>
  );
}

export default App;
