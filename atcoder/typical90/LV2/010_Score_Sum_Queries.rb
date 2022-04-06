n = gets.to_i
arr = Array.new(2).map{ Array.new(n+1, 0) }
n.times do |i|
  c, p = gets.split(' ').map(&:to_i)
  arr[c-1][i+1] += p
end
(0...n).each do |j|
  arr[0][j+1] += arr[0][j]
  arr[1][j+1] += arr[1][j]
end
q = gets.to_i
q.times do
  l, r = gets.split(' ').map(&:to_i)
  puts "#{arr[0][r] - arr[0][l-1]} #{arr[1][r] - arr[1][l-1]}"
end