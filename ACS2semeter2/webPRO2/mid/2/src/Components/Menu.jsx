import MenuItem from "./MenuItem"


const Menu = () => {
  return (
  <>
 <nav>
    <ul>
        <MenuItem href="/" icon="home" />
        <MenuItem href="/services" icon="service" />
        <MenuItem href="/pricing" icon="pricing" />
        <MenuItem href="/blog" icon="blog" />
        
    </ul>
 </nav>
  </>    
  )
}

export default Menu
