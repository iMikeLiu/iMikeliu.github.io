function chk(data)
{
	var text =$("#"+data).val();
$.get("/markdown/"+text,function(data){
 	document.getElementById("Text").innerHTML=data;}
);
}
