
-- 1 . Net cases , net Deaths as compared to net death percentage as cumulative  of each continent 
SELECT  
	sum( new_cases ) as total_cases ,	sum( cast(new_deaths as int )  ) as total_deaths , 
	round(sum( cast(new_deaths as float )  )/sum( (new_cases)  )*100  ,2)as DeathPercentage
from 
	CovidTestDB..CovidDeaths
where	
	continent is not null
order by 1,2 

-- 2.
 
-- 3.  Highest infection rates as compared to percentage of population infected
Select Location, Population,  Max(CAST(total_cases AS FLOAT)) as HighestInfectionCount,  Max(CAST(total_cases AS FLOAT)/population)*100 as PercentPopulationInfected
From CovidTestDB..CovidDeaths
--Where location like '%states%'
Group by Location, Population
order by PercentPopulationInfected desc

-- 4  Highest Infection rate v/s perentage of population infected for each date
Select Location, Population,date, Max(CAST(total_cases AS FLOAT))as HighestInfectionCount, Max(CAST(total_cases AS FLOAT)/population)*100  as PercentPopulationInfected
From CovidTestDB..CovidDeaths
--Where location like '%states%'
Group by Location, Population, date
order by PercentPopulationInfected desc