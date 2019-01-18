function X=vectprod(vect)
%this function calculate the vectorial product in my way
nr=length(vect);
if nr~=3
    X=nr;
    error('This is working only for bidimensional space');
end
mat=vect(1,:)'*vect(2,:);
X=zeros(1,3);
X(1)=mat(2,3)-mat(3,2);
X(2)=mat(3,1)-mat(1,3);
X(3)=mat(1,2)-mat(2,1);
