function H=hilbert(n)
%this return the n dimensional Hilbert matrix
for i=1:n
    for j=1:n
        H(i,j)=1/(i+j-1);
    end
end
