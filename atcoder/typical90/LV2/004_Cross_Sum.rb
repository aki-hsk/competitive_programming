h, w = gets.split(' ').map(&:to_i)
board = []
h.times { board << gets.chomp.split(' ').map(&:to_i) }
h_sum = Array.new(h, 0)
w_sum = Array.new(w, 0)

(0...h).each {|i| h_sum[i] = board[i].sum }
(0...w).each do |j|
  sum = 0
  (0...h).each do |i|
    sum += board[i][j]
  end
  w_sum[j] = sum
end

(0...h).each do |i|
  (0...w).each do |j|
    print "#{h_sum[i] + w_sum[j] - board[i][j]} "
  end
  puts
end