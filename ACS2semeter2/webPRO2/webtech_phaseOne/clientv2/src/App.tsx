import React from "react";

interface CommenntComponent {
  comment: string;
  showComment(prefix: string): React.ReactNode;
}

class Comment implements CommenntComponent {
  constructor(public comment: string) {}
  showComment(prefix: string): React.ReactNode {
    return (
      <div>
        {prefix} {this.comment}
      </div>
    );
  }
}

class Post implements CommenntComponent {
  chidern: CommenntComponent[] = [];

  constructor(public comment: string) {}

  addComponent(component: CommenntComponent) {
    this.chidern.push(component);
  }

  showComment(prefix: string): React.ReactNode {
    return (
      <div>
        {prefix} {this.comment}
        {this.chidern.map((child) => child.showComment(prefix + "-"))}
      </div>
    );
  }
}

function App() {
  const post = new Post("Post");
  const comment1 = new Comment("Comment 1");
  const comment2 = new Comment("Comment 2");

  post.addComponent(comment1);

  const post2 = new Post("Post 2");
  post2.addComponent(comment2);
  return (
    <>
      {post.showComment("")}
      {post2.showComment("")}
    </>
  );
}

export default App;
