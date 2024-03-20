
const MenuItem = ({href , icon}) => {
  return (
  <>
    <li>
        <a href={href}>{icon}</a>
    </li>
  </>    
  )
}

export default MenuItem
