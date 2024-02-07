/* eslint-disable react/prop-types */
import { useState } from "react";

function App() {
  const [tasks, setTasks] = useState([
    { id: "1", title: "flutter", completed: false, state: false },
    { id: "2", title: "Backend", completed: false, state: false },
    { id: "3", title: "fontend", completed: false, state: false },
  ]);

  const handleCheck = (id) => {
    const newTasks = tasks.map((task) => {
      if (task.id === id) {
        return {
          ...task,
          completed: !task.completed,
        };
      }
      return task;
    });
    setTasks(newTasks);
  };

  const handleShow = async () => {
    tasks.filter((task) => {
      if (task.completed === true) {
        task.state = true;
      }
      return task;
    });
    await setShow(true);
    setShow(false);
  };

  const [show, setShow] = useState(true);

  const CheckBOx = ({ id, title, completed, show, state }) => {
    return (
      <>
        <div
          onClick={() => handleCheck(id)}
          style={
            show || !completed || !state
              ? { display: "flex" }
              : { display: "none" }
          }
        >
          <input type="checkbox" name={id} defaultChecked={completed} />
          <label htmlFor={id}>{title}</label>
        </div>
      </>
    );
  };

  return (
    <>
      <h1>Todo List</h1>
      <button onClick={() => setShow(true)}>Show</button>
      <button onClick={handleShow}>Hide</button>
      {tasks.map((task) => (
        <CheckBOx
          key={task.id}
          id={task.id}
          title={task.title}
          completed={task.completed}
          state={task.state}
          show={show}
        />
      ))}
    </>
  );
}

export default App;
