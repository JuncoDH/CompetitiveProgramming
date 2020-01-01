{-
  Sheldon Numbers
  Haskell solution and test case generator

  Pedro Vasconcelos <pbv@dcc.fc.up.pt> 2015
-}
import           Control.Monad(forM_)
import           Data.Set (Set)
import qualified Data.Set as Set
import Data.Bits (shiftL, (.|.))
import Data.Int (Int64)

type Long = Int64

-- two kinds of sheldon numbers
-- Kind 1: 1^n (0^m 1^n)*
-- Kind 2: 1^n (0^m 1^n)* 0^m
data Kind = K1 | K2 deriving Show


-- expand a sheldon number
sheldon :: Kind -> Int -> Int -> Int -> Long
sheldon k n m count = case k of
  K1 -> expand count ones
  K2 -> expand count ones `shiftL` m 
  where ones = 2^n - 1
        expand 0 acc = acc
        expand c acc = expand (c-1) ((acc `shiftL` (n+m)) .|. ones)

-- number of bits of a sheldon number
size :: Kind -> Int -> Int -> Int -> Int
size K1 ones zeros count = ones + count*(ones+zeros)
size K2 ones zeros count = ones + count*(ones+zeros) + zeros

-- all sheldon numbers with up-to 63 bits 
sheldons  = Set.fromList
            [ sheldon kind ones zeros count
            | kind <- [K1, K2],
              ones <- [1..limit], zeros <-[0..limit-ones],
              count <- takeWhile (\c -> size kind ones zeros c <= limit) [0..]
            ]
    where limit = 63

-- sheldon numbers between two integers
solve :: (Long,Long) -> Set Long
solve (lo,hi) | lo <= hi = Set.filter (\x -> x >= lo && x <= hi) sheldons

main = do
  [n,m] <- fmap words getLine
  print $ Set.size $ solve (read n, read m)


-- test case generation
small_tests = [ (1,10), (70,75),  (100,111), (1700, 1799) ]

large_tests = [ (10^i, 10^(2*i+1)) | i<-[1..6]] ++ [ (0, 2^63-1) ]

singleton_tests = map (\n -> (n,n)) nums ++ map (\n -> (n+1,n+1)) nums
    where nums = [sheldon k n m c | 
                  k <- [K1,K2], c<-[1,2], (n,m)<-[(2,3),(3,2)] ]

all_tests = small_tests ++ large_tests ++ singleton_tests 

writeTests
  = forM_ (zip [0..] all_tests) $ \(n,tst) -> writeTest ("test"++show n) tst

writeTest file (lo,hi) = do
  writeFile (file ++ ".in") (unwords [show lo, show hi] ++ "\n")
  writeFile (file ++ ".out") (show (Set.size $ solve (lo,hi))  ++ "\n")
