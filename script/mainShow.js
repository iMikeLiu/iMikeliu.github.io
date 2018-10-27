$.get("/markdown/main.md",function(data){
  var html=marked(data)
  document.getElementById("main").innerHTML=html;
}
);
 
