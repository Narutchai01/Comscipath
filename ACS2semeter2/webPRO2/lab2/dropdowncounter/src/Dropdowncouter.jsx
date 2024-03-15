import { useState } from 'react'

const App = () => {
  const [count,setCount] = useState(0)
  const arr = [1,2,3,4,5]

  const handleCount = (e) => {
    if (e.button == -1) {
      setCount(count + parseInt(e.target.value))
    }
  }

  return (
    <>
      <h1>Counter : {count}</h1>
      <select onClick={handleCount}>
        {arr.map((item, index) => <option key={index} value={item}>{item}</option>)}
      </select>
    </> 
  )
}

App.displayName = 'App'

export default App
