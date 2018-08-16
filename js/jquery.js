$(document).ready(function(){

    $("input").hover(
      function(){
        $(this).css("background-color", "#cccccc");
    },
      function(){
        $(this).css("background-color", "#ffffff");
    });
    $("input").focus(function()
    {
    		$(this).animate({ margin: '0% 20% 0% 20%' ,width : '50%', }, 'slow');
    		$(this).animate({ margin: '3px' ,width : '100%'}, 'slow');
    });
    
    $("input[type='submit']").hover(
      function(){
        $(this).css("background-color", "#cccccc");
    },
      function(){
        $(this).css("background-color", "teal");
      });
});
