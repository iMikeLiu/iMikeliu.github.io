  var u = navigator.userAgent;
  var isAndroid = u.indexOf('Android') > -1 || u.indexOf('Adr') > -1;
   var isiOS = !!u.match(/\(i[^;]+;( U;)? CPU.+Mac OS X/);
if(isAndroid)
{
(function(doc, win){
    var docE1 = doc.documentElement,
        resizeEvt = 'orientationchange' in window ? 'orientationchange' : 'resize',
        recalc = function(){
            var clientWidth = docE1.clientWidth;
            if(!clientWidth) return;
            docE1.style.fontSize = 20 * (clientWidth / 320) + 'px';            
        };

    if (!doc.addEventListener) return;
    win.addEventListener(resizeEvt,recalc,false);
    doc.addEventListener('DOMContentLoaded',recalc,false);
})(document,window);

}
if(isiOS)
{
	(function(doc, win){
    var docE1 = doc.documentElement,
        resizeEvt = 'orientationchange' in window ? 'orientationchange' : 'resize',
        recalc = function(){
            var clientWidth = docE1.clientWidth;
            if(!clientWidth) return;
            docE1.style.fontSize = 20 * (clientWidth / 320) + 'px';            
        };

    if (!doc.addEventListener) return;
    win.addEventListener(resizeEvt,recalc,false);
    doc.addEventListener('DOMContentLoaded',recalc,false);
})(document,window);
}