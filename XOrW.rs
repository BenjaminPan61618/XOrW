use std::env;
fn main(){
let key="XDG_SESSION_TYPE";
 match env::var_os(key){
  Some(val) => println!("当前会话环境 / {}: {:?}", key, val),
  None => println!("{} is not defined in the environment.", key)
}
}
