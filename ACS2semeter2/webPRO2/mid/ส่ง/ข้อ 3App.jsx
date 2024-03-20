import { useState,useEffect } from "react";

function App() {
  const [time, setTime] = useState({
    minutes: 0,
    seconds: 0,
  });
  const [isRunning, setIsRunning] = useState(false);

  const handleChange = (e) => {
    setTime({ ...time, [e.target.name]: parseInt(e.target.value) });
  };




useEffect(() => {
  if (isRunning) {
    const interval = setInterval(() => {
      if (time.seconds === 0) {
        if (time.minutes === 0) {
          clearInterval(interval);
          setIsRunning(false);
        } else {
          setTime({ minutes: time.minutes - 1, seconds: 59 });
        }
      } else {
        setTime({ minutes: time.minutes, seconds: time.seconds - 1 });
      }
    }, 1000);
    return () => clearInterval(interval);
    
  }
}, );


const timerSting = `${time.minutes.toString().padStart(2,"0") || 0}:${time.seconds.toString().padStart(2, "0") || 0}`
  return (
    <>
      <form>
        <label>
          Enter Minutes:
          <input type="number" min={0} max={60} name="minutes" onChange={handleChange} />
        </label>
        <label>
          Enter Minutes:
          <input type="number" min={0} max={60} name="seconds" onChange={handleChange} />
        </label>
      </form>
      <div>
        <h1>{time.minutes || time.seconds  ? timerSting : "Time Out"}</h1>
      </div>
      <button onClick={()=> setIsRunning(!isRunning)}>{isRunning ? "Stop" : "Start"}</button>
 
    </>
  );
}

export default App;
