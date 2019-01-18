%function gui()
hpb=uicontrol('Style','Pushbutton','Units','normalized',...
    'Position',[.1 .8 .3 .1],'Callback','cla','String',...
    'Buton prin apasare');
hrb=uicontrol('Style','Radiobutton','Units','normalized',...
    'Position',[.6 .8 .3 .1],'Callback','cla','String',...
    'Buton radio');
hsl=uicontrol('Style','Slider','String','Potentiometru liniar',...
    'Units','normalized','Position',[.1 .5 .3 .1],'Min',100,'Max',...
    200,'Value',100);
hpm=uicontrol('Style','Popup','String','hsv|hot|cool|gray|',...
    'Units','normalized','Position',[.1 .2 .3 .1],'Callback','setmap');
hcb=uicontrol('Style','Checkbox','String','Cutie de control',...
    'Units','normalized','Position',[.6 .5 .3 .1],'Callback','figure');
hed=uicontrol('Style','Edit','String','Cutie de editare','Units',...
    'normalized','Position',[.6 .2 .3 .1]);