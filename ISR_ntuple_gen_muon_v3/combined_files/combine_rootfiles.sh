MG=`ls ../../*muon*madgraph*`
MCatNLO=`ls ../../*muon*MCatNLO*`

hadd -f MG.root $MG
hadd -f MCatNLO.root $MCatNLO
