import { useState } from "react"

function App() {

  const [number ,setNumber] = useState(0)
  const [defualtNumber ,setDefualtNumber] = useState(0)


  const handleSubmit = (e) => {
    e.preventDefault();
    setNumber(defualtNumber)
  };

  const handleAdd = () => {
    setNumber(parseInt(number) + 1)
  }

  const handleDEvalue = () => {
    setNumber(parseInt(number) - 1)
  }

  const handleDivide = () => {
    setNumber(parseInt(number) / 2)
  };

  const handleReset = () => {
    setNumber(defualtNumber)
  };

  return (
    <>
    <h1>{number || 0}</h1>
    <form onSubmit={handleSubmit}>
      <label>
        Enter number here 
        <input type="number" onChange={(e)=> setDefualtNumber(e.target.value)}/>
      </label>
      <button>Submit</button>
    </form>
    <div>
      <button onClick={handleAdd}>add</button>
      <button onClick={handleDEvalue}>Devalue</button>
      <button onClick={handleDivide}>Divide</button>
      <button onClick={handleReset}>Reset</button>
    </div>
    </>
  )
}

export default App
