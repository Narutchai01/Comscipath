import { useState } from 'react'
import './App.css'

function App() {

  const [number, setNumber] = useState(0)
  const [sum , setSum] = useState(0)

  const handleSubmit = (e) => {
    e.preventDefault()
    setSum(sum + parseInt(number))
  };

  return (
    <>
      <form onSubmit={handleSubmit}>
      <label >
        Number : 
        <input type="number" value={number} onChange={(e) => setNumber(e.target.value)} />
      </label>
      <div>
        Sum : {sum}
      </div>
      <button>sum</button>
      </form>
    </>
  )
}

export default App
