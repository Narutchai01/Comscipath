interface BlongInsterface {
  title: string;
  description: string;
  showComPonents: React.ReactNode;
}

class Blog implements BlongInsterface {
  title: string;
  description: string;
  showComPonents: React.ReactNode;

  constructor(
    title: string,
    description: string,
    showComPonents: React.ReactNode
  ) {
    this.title = title;
    this.description = description;
    this.showComPonents = showComPonents;
  }
}

class Catagonry {
  name: string;
  blogs: Blog[] = [];

  constructor(name: string, blogs: Blog[]) {
    this.name = name;
    this.blogs = blogs;
  }

  addBlog(blog: Blog) {
    this.blogs.push(blog);
  }

  showBlogs() {
    return this.blogs.map((blog, index) => (
      <div key={index}>
        <h2>{blog.title}</h2>
        <p>{blog.description}</p>
        {blog.showComPonents}
      </div>
    ));
  }
}

function App() {

  const blog1 = new Blog('Blog 1', 'Description 1', <div>Blog 1</div>);
  const blog2 = new Blog('Blog 2', 'Description 2', <div>Blog 2</div>);
  const blog3 = new Blog('Blog 3', 'Description 3', <div>Blog 3</div>);


  const catagory1 = new Catagonry('Catagory 1', [blog1, blog2]);

  catagory1.addBlog(blog3);

  

  return (
    <div>
      {catagory1.showBlogs()}
      <h1>App</h1>
    </div>
  );
}

export default App;
