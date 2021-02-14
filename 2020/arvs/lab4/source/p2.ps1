New-ADGroup -GroupScope DomainLocal  -Name Group1
New-ADGroup -GroupScope DomainLocal  -Name Group2
New-ADGroup -GroupScope DomainLocal  -Name Group3
Get-ADGroup -Filter 'name -like "Group*"' | Set-ADGroup -GroupScope Universal
Get-ADGroup -Filter 'name -like "Group*"' | Set-ADGroup -GroupScope Global
New-ADUser -Name User1
New-ADUser -Name User2
New-ADUser -Name User3
Add-ADGroupMember -Identity Group1 -Members User1,User2,User3
Get-ADGroupMember -Identity Group1
Get-ADGroupMember Group1 | ForEach-Object {
  Add-ADGroupMember -Identity Group2 -Members $_
  Remove-ADGroupMember -Identity Group1 -Members $_
}
Get-ADGroupMember -Identity Group1