import { useState, useEffect } from "react";

// function HexFunc() {

//   const PLACEHOLDER = `conic-gradient(
//     gray 0.25turn, white 0 0.5turn,
//     gray 0.75turn, white 0 1turn,
//   )`
//   const [color , setColor] = useState("BADA55");

//   const handleChange = (e) => {
//     setColor(e.target.value.replace(/[^0-9a-f]/gi,"").toUpperCase());
//   };

//   const outputstyle = {
//     width : "20px",
//     border : "1px solid",
//     background : color.length === 6 ? `#${color}` : PLACEHOLDER
//   }

//   return(
//     <form>
//       <label>
//         Hex color
//         <input type="text" value={color} onChange={handleChange} />
//       </label>
//       <div style={outputstyle}>
//         <h1>hello</h1>
//       </div>
//     </form>
//   )
// }

// function App() {
//   // return HexFunc();
//   const [qurity, setQurity] = useState(0);
//   const [arr, setArr] = useState([]);

//   const randomNumber = (min, max) => {
//     return Math.floor(Math.random() * (max - min + 1) + min);
//   };

//   useEffect(() => {
//     const arr = [];
//     for (let i = 0; i < qurity; i++) {
//       arr.push(randomNumber(1,6));
//     }
//     setArr(arr);
//   }, [qurity]);



//   return (
//     <div>
//       <form>
//         <label>
//           Enter here
//           <input
//             type="number"
//             value={qurity}
//             onChange={(e) => setQurity(e.target.value)}
//           />
//         </label>
//       </form>
//       {
//         arr.map((item, index) => (
//           <div key={index}>{item}</div>
//         ))
//       }
//     </div>
//   );
// }


function App() {
  // return HexFunc();
  const [qurity, setQurity] = useState(0);
  const [arr, setArr] = useState([]);


  const randomNumber = (min, max) => {
    return Math.floor(Math.random() * (max - min + 1) + min);
  };

  const handleSubmit = (e) => {
    e.preventDefault();
    const arr = [];
    for (let i = 0; i < qurity; i++) {
      arr.push(randomNumber(1,6));
    }
    setArr(arr);
  };

  return (
    <>
      <form onSubmit={handleSubmit}>
        <label>
          Enter number
          <input type="number" onChange={(e)=> setQurity(e.target.value)}/>
        </label>
        <button type="submit">Submut</button>
      </form>

      {
        arr.map((item, index) => (
          <div key={index}>{item}</div>
        ))
      }
    </>

  );
}


export default App;
