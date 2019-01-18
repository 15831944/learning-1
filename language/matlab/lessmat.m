function X=lessmat(x,val)
%it returns a matrix with the elements less than val from x
[i,j]=find(x<val);
for k=1:length(i)
    X(i(k),j(k))=x(i(k),j(k));
end