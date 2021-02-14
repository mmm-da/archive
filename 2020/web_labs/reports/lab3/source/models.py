from uuid import uuid4
from django.db import models


class Thing(models.Model):
    id = models.UUIDField(primary_key=True, default=uuid4, editable=False)
    name = models.CharField(max_length=100)
    description = models.TextField()


class ThingInstance(models.Model):
    id = models.UUIDField(primary_key=True, default=uuid4, editable=False)
    storage = models.ForeignKey(
        'storages.Section',
        on_delete=models.CASCADE
    )
    type = models.ForeignKey(
        'Thing',
        on_delete=models.CASCADE
    )
    count = models.IntegerField()

