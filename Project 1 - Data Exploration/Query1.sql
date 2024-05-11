-- SELECT STATEMENTS TO ENSURE TABLES WERE IMPORTED CORRECTLY
-- COMMENT SHORTCUTS , CTRL + K , CTRL + C , U FOR UNDO 

--SELECT TOP (100) *

SELECT *
FROM CovidTestDB..CovidDeaths
where continent is null
--  FROM [testDB].[dbo].[CovidDeaths]


-- 1 . Finding death percentage in united states 
-- needs to be casted as division of 2 INTS Produces an INT result
select 
	location ,
	date ,
	(total_cases) ,
	(total_deaths) ,
	ROUND( CAST(total_deaths AS FLOAT) / total_cases * 100  , 2) as 'Death Percentage'
from 
	CovidTestDB..CovidDeaths
where 
	location like '%states%'
order by 1,2 


-- 2 . countries with highest infection rates compared to population
--SELECT location , date , total_cases , population , (ROUND (CAST(total_cases AS FLOAT)/population  * 100,2)) AS 'Infection Percentage For Each Country'
SELECT 
	location  ,
	ROUND(SUM(ROUND (CAST(total_cases AS FLOAT)/population  * 100,2)) ,2 ) AS 'NET Infection Percentage For Each Country'
from 
	CovidTestDB..CovidDeaths
GROUP BY 
	location -- , date , total_cases , population
ORDER BY 
	location

-- 3. MAX infection rate OBSERVED for each coutry 
SELECT 
	location ,
	MAX(ROUND (CAST(total_cases AS FLOAT)/population  * 100,2)) AS 'MAX Infection Percentage For Each Country'
from 
	CovidTestDB..CovidDeaths
GROUP BY 
	location 
ORDER BY 
	location


-- 4 . Showing countries with death count per population
SELECT 
	LOCATION , (MAX( total_deaths )) AS 'Net Death Count'
from 
	CovidTestDB..CovidDeaths
where 
	continent is not null
GROUP BY 
	location
order by 
	'Net Death Count' desc

-- 5. Showing max death count per continents
SELECT 
	continent , 
	(MAX( total_deaths )) AS 'Net Death Count Per Continent'
from 
	CovidTestDB..CovidDeaths
where 
	continent is not null
GROUP BY 
	continent
order by 
	'Net Death Count Per Continent' desc


-- 6. Sum of emerging cases throughout the world and new cases appearing with date
SELECT 
	Date , sum( cast(new_cases as int )  ) as emerging_cases
from 
	CovidTestDB..CovidDeaths
where 
	continent is not null
group by 
	date 
having 
	sum( cast(new_cases as int )  ) != 0 
order by 1,2 

SELECT  
	sum( new_cases ) as total_cases ,
	sum( cast(new_deaths as int )  ) as total_deaths , 
	round(sum( cast(new_deaths as float )  )/sum( (new_cases)  )*100  ,2)as DeathPercentage
from 
	CovidTestDB..CovidDeaths
where 
	continent is not null
--group by date 
--having sum( cast(new_cases as int )  ) != 0 
order by 
	1,2 


-- 8 . Looking at Total Population vs Total Vaccination for each location
select 
	CD.continent,
	cv.location ,
	CD.date,
	(CD.population)  ,
	(CV.total_vaccinations ) ,
	cv.new_vaccinations
from 
	CovidTestDB..CovidVaccinations CV JOIN CovidTestDB..CovidDeaths CD
ON 
	CV.date = CD.date
ORDER BY 2,3


select 
	CD.continent ,
	cv.location ,
	CD.date ,
	(CD.population) ,
	cv.new_vaccinations , 
	sum(CONVERT(INT,CV.new_vaccinations))	OVER (PARTITION BY CV.LOCATION ORDER BY CD.LOCATION , CD.date) as RollingPeopleVaccinated 
-- select CD.continent , cv.location , CD.date ,sum(cast(CD.population as bigint)) , sum(cast(CV.total_vaccinations as bigint))
from 
	CovidTestDB..CovidVaccinations CV JOIN CovidTestDB..CovidDeaths CD
ON 
	CV.date = CD.date
group by cv.location ;

-- use cte

with PopvsVacc (continent,location,date,population,new_vaccinations,RollingPeopleVaccinated)
as 
(
select 
	CD.continent ,
	cv.location ,
	CD.date ,
	(CD.population) ,
	cv.new_vaccinations , 
	sum(CONVERT(BIGINT,CV.new_vaccinations)) OVER (PARTITION BY CV.LOCATION ORDER BY CD.LOCATION , CD.date) as RollingPeopleVaccinated 
-- select CD.continent , cv.location , CD.date ,sum(cast(CD.population as bigint)) , sum(cast(CV.total_vaccinations as bigint))
from 
	CovidTestDB..CovidVaccinations CV JOIN CovidTestDB..CovidDeaths CD
	ON CV.date = CD.date 
	AND CV.location = CD.location
WHERE 
	CD.continent IS NOT NULL
-- ORDER BY 2,3 
)

select * , ROUND(( cast(RollingPeopleVaccinated as decimal(18,2))/ population ) * 100  ,2)as 'Percentage people vaccinated'
from PopvsVacc ;
------------------------------------------------

-- Drop the view if it exists
IF OBJECT_ID('PercentPopulationVaccinated', 'V') IS NOT NULL
    DROP VIEW PercentPopulationVaccinated;
GO

-- CREATING VIEW FOR DATA VISUALISATION

CREATE VIEW PercentPopulationVaccinated as
select 
	CD.continent , 
	cv.location , 
	CD.date ,
	(CD.population) , 
	cv.new_vaccinations , 
	sum(CONVERT(BIGINT,CV.new_vaccinations))	OVER (PARTITION BY CV.LOCATION ORDER BY CD.LOCATION , CD.date) as RollingPeopleVaccinated 
from 
	CovidTestDB..CovidVaccinations CV 
JOIN 
	CovidTestDB..CovidDeaths CD	ON CV.date = CD.date AND CV.location = CD.location
WHERE CD.continent IS NOT NULL ;

select * from PercentPopulationVaccinated ;