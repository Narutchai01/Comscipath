import React, { useState } from "react";

// Component interface
interface TaskComponent {
  name: string;
  showStructure(prefix: string): React.ReactNode;
}

class Task implements TaskComponent {
  constructor(public name: string) {}

  showStructure(prefix: string): React.ReactNode {
    return (
      <span>
        {prefix}
        {this.name}
      </span>
    );
  }
}

class Directory implements TaskComponent {
  children: TaskComponent[] = [];

  constructor(public name: string) {}

  addComponent(component: TaskComponent) {
    this.children.push(component);
  }

  showStructure(prefix: string): React.ReactNode {
    return (
      <div>
        <b>
          {prefix}
          {this.name}
        </b>
        <ul>
          {this.children.map((child, index) => (
            <li key={index}>{child.showStructure(`${prefix} `)}</li>
          ))}
        </ul>
      </div>
    );
  }
}

const App = () => {
  const [newFileName, setNewFileName] = useState("");
  const [newDirectoryName, setNewDirectoryName] = useState("");
  const [root] = useState(new Directory("root"));

  const handleCreate = () => {
    if (newFileName.trim() && newDirectoryName.trim()) {
      const ArrDir = newDirectoryName.split("/");
      const newFile = new Task(newFileName.trim());
      if (ArrDir.length > 1) {
        let currentDir = root;
        for (let i = 0; i < ArrDir.length; i++) {
          const newDir = new Directory(ArrDir[i]);
          currentDir.addComponent(newDir);
          currentDir = newDir;
        }
        currentDir.addComponent(newFile);
      } else {
        const newDir = new Directory(ArrDir[0]);
        root.addComponent(newDir);
        newDir.addComponent(newFile);
      }
      setNewFileName("");
      setNewDirectoryName("");
    } else if (newFileName.trim() && !newDirectoryName.trim()) {
      const newFile = new Task(newFileName.trim());
      root.addComponent(newFile);
      setNewFileName("");
    } else if (!newFileName.trim() && newDirectoryName.trim()) {
      const ArrDir = newDirectoryName.split("/");
      if (ArrDir.length > 1) {
        let currentDir = root;
        for (let i = 0; i < ArrDir.length; i++) {
          const newDir = new Directory(ArrDir[i]);
          currentDir.addComponent(newDir);
          currentDir = newDir;
        }
        setNewDirectoryName("");
      } else {
        const newDir = new Directory(ArrDir[0]);
        root.addComponent(newDir);
        setNewDirectoryName("");
      }
    }
  };

  return (
    <div>
      <h1>File System</h1>
      {root.showStructure("")}
      <div>
        <input
          type="text"
          value={newFileName}
          onChange={(e) => setNewFileName(e.target.value)}
          placeholder="Enter a file name"
        />
      </div>
      <div>
        <input
          type="text"
          value={newDirectoryName}
          onChange={(e) => setNewDirectoryName(e.target.value)}
          placeholder="Enter a directory name"
        />
      </div>
      <button onClick={handleCreate}>Create File</button>
    </div>
  );
};

export default App;
