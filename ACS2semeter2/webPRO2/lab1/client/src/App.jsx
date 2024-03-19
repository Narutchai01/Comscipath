
import { useState, useEffect } from "react";

function App() {
  const [time, setTime] = useState(10);
  const [isRunning, setIsRunning] = useState(false);

  useEffect(() => {
    if (isRunning && time > 0) {
      const interval = setInterval(() => {
        setTime(time- 1);
      },1000);
      return () => clearInterval(interval);
    }
  }, [isRunning, time]);


  const reset = () => {
    setTime(10);
    // setIsRunning(false);
  };

  return (
    <>
      <h1>Time letft : {time} seconds</h1>
      <div>
        <button onClick={reset}>Reset</button>
        <button onClick={() => setIsRunning(!isRunning)}>
          {isRunning ? "Pause" : "Resume"}
        </button>
      </div>
    </>
  );
}

export default App;
